#include <stdio.h>
#include <stdlib.h>

typedef struct celldata
{
  int paths_from_above;
  int paths_from_below;
  int paths_from_left;
  int paths_from_right;

  int *paths_from_above_len;
  int *paths_from_below_len;
  int *paths_from_left_len;
  int *paths_from_right_len;

}celldata;


typedef struct mgrid
{
  int       **mgrid_cells;
  int         mgrid_alivecells;
  int         mgrid_nrows;
  int         mgrid_ncols;
  int         mgrid_startxy;
  int         mgrid_endxy;
  celldata  **mgrid_celldata;
}mgrid;

int parsefile(mgrid *mazegrid)
{
  FILE *inputFilePtr;
  char s[1000];
  int i = 0, nlines = 1, numc = 0, ncells = 0, rows = 0, cols = 0;
  int **grid;
  celldata **mcells;

  inputFilePtr = fopen("testmaze.txt", "r");

  numc = fread(s, 1, 1000, inputFilePtr);

  for (i = 0; i < numc; i++)
  {
    if (s[i] == '\n')
      nlines+=1;
    else if (s[i] != ' ')
      ncells+=1;
  }
  printf("total %d nlines %d ncells %d\n", numc, nlines, ncells);
  grid = (int**) malloc(sizeof(int*) * nlines);
  mcells = malloc(sizeof(celldata*) * nlines);

  mazegrid->mgrid_ncols = ncells/nlines;
  mazegrid->mgrid_nrows = nlines;

  for (i = 0; i < numc; i++)
  {
    grid[i] = malloc(sizeof(int) * ncells/nlines);
    mcells[i] = malloc(sizeof(celldata) * ncells/nlines);
  }

  for (i = 0; i < numc; i++)
  {
    if (s[i] == '\n')
    {
      rows+=1;
      cols = 0;
    }
    else if (s[i] == ' ')
      cols+=1;
    else
    {
      grid[rows][cols] = s[i] - '0';
    }
  }

  mazegrid->mgrid_cells = grid;
  mazegrid->mgrid_celldata = mcells;
  return 0;
}

int validatecell(mgrid *mazegrid, int i, int j)
{
  int temp = 0;
  if (i > 0)
    temp+=mazegrid->mgrid_cells[i-1][j];
  if (j > 0)
    temp+=mazegrid->mgrid_cells[i][j-1];
  if (i < mazegrid->mgrid_nrows)
    temp+=mazegrid->mgrid_cells[i+1][j];
  if (j < mazegrid->mgrid_ncols)
    temp+=mazegrid->mgrid_cells[i][j+1];

  return temp;
}

int  validategrid(mgrid *mazegrid)
{
  int i = 0, j = 0;

  for (i = 0; i < mazegrid->mgrid_nrows; i++)
  {
    for (j = 0; j < mazegrid->mgrid_ncols; j++)
    {
      if (mazegrid->mgrid_cells[i][j] != 0)
      {
        if( validatecell(mazegrid, i, j) == 0)
          return 1;
      }
    }
  }
  return 0;
}

int printgrid(mgrid *mazegrid)
{
  int i = 0, j = 0;

  mazegrid->mgrid_alivecells = 0;
  for (i = 0; i < mazegrid->mgrid_nrows; i++)
  {
    for (j = 0; j < mazegrid->mgrid_ncols; j++)
    {
      printf("%d ", mazegrid->mgrid_cells[i][j]);
      if (mazegrid->mgrid_cells[i][j] == 3)
      {
        mazegrid->mgrid_endxy = i*10+j;
        mazegrid->mgrid_alivecells+=1;
      }
      else if (mazegrid->mgrid_cells[i][j] == 2)
      {
        mazegrid->mgrid_startxy = i*10+j;
        mazegrid->mgrid_alivecells+=1;
      }
      else if (mazegrid->mgrid_cells[i][j] == 1)
      {
        mazegrid->mgrid_alivecells+=1;
      }
    }
    printf("\n");
  }
  return 0;
}

int init_cells(mgrid *mazegrid)
{
  int i = 0, j = 0, k = 0;
  for (i = 0; i < mazegrid->mgrid_nrows; i++)
  {
    for (j = 0; j < mazegrid->mgrid_ncols; j++)
    {
      mazegrid->mgrid_celldata[i][j].paths_from_above = 0;
      mazegrid->mgrid_celldata[i][j].paths_from_below = 0;
      mazegrid->mgrid_celldata[i][j].paths_from_left  = 0;
      mazegrid->mgrid_celldata[i][j].paths_from_right = 0;

      mazegrid->mgrid_celldata[i][j].paths_from_above_len =
        malloc(sizeof(int) * mazegrid->mgrid_alivecells);
      mazegrid->mgrid_celldata[i][j].paths_from_below_len =
        malloc(sizeof(int) * mazegrid->mgrid_alivecells);
      mazegrid->mgrid_celldata[i][j].paths_from_left_len  =
        malloc(sizeof(int) * mazegrid->mgrid_alivecells);
      mazegrid->mgrid_celldata[i][j].paths_from_right_len =
        malloc(sizeof(int) * mazegrid->mgrid_alivecells);
      for (k = 0; k < mazegrid->mgrid_alivecells; k++)
      {
        mazegrid->mgrid_celldata[i][j].paths_from_right_len[k] = 0;
        mazegrid->mgrid_celldata[i][j].paths_from_left_len[k] = 0;
        mazegrid->mgrid_celldata[i][j].paths_from_above_len[k] = 0;
        mazegrid->mgrid_celldata[i][j].paths_from_below_len[k] = 0;
      }

    }
  }
  return 0;
}
int printpath(int path_so_far[][10], mgrid *mazegrid)
{
  int i = 0, j = 0;
  int temp = 0;
  for (i = 0; i < mazegrid->mgrid_nrows; i++)
  {
    for (j = 0; j < mazegrid->mgrid_ncols; j++)
    {
      printf("%u ",path_so_far[i][j]);
    }
    printf("\n");
  }
  return temp;
}


int findcellvisited(int path_so_far[][10], mgrid *mazegrid)
{
  int i = 0, j = 0;
  int temp = 0;
  for (i = 0; i < mazegrid->mgrid_nrows; i++)
  {
    for (j = 0; j < mazegrid->mgrid_ncols; j++)
    {
      temp+=path_so_far[i][j];
    }
  }
  return temp;
}

int copypaths(int path_so_far_res[][10], int path_so_far[][10], mgrid *mazegrid)
{
  int i = 0, j = 0;
  for (i = 0; i < mazegrid->mgrid_nrows; i++)
  {
    for (j = 0; j < mazegrid->mgrid_ncols; j++)
    {
      path_so_far_res[i][j] = path_so_far[i][j];
    }
  }
  return 0;
}

int findpaths(mgrid *mazegrid, int i, int j, int path_so_far[][10],
              int required_len)
{
  int path_so_farl[10][10];
  int path_so_farr[10][10];
  int path_so_fara[10][10];
  int path_so_farb[10][10];

  //printf("cell %u %u req %u r %u c %u\n", i, j, required_len,
    //mazegrid->mgrid_nrows, mazegrid->mgrid_ncols);

  if (mazegrid->mgrid_cells[i][j] == 3 && required_len == 0)
  {
    if (findcellvisited(path_so_far, mazegrid) == mazegrid->mgrid_alivecells)
      printf("hello\n");
    else
      printf("hi %u\n", findcellvisited(path_so_far, mazegrid));
    return 0 ;
  }
  else if (mazegrid->mgrid_cells[i][j] == 3 && required_len > 0)
  {
    printf("wrong path %u\n", required_len);
    return 1;
  }
  else if (required_len == 0)
  {
    printf("dead end %u\n", mazegrid->mgrid_alivecells);
    printpath(path_so_far, mazegrid);
    return 1;
  }

  path_so_far[i][j] = 1 ;


  if (i > 0)
  {
    if (path_so_far[i-1][j] != 1 && mazegrid->mgrid_cells[i-1][j] > 0)
    {
      copypaths(path_so_fara, path_so_far, mazegrid);
      findpaths(mazegrid, i-1, j, path_so_fara, required_len-1);
    }
  }
  if (j > 0)
  {
    if (path_so_far[i][j-1] != 1 && mazegrid->mgrid_cells[i][j-1] > 0)
    {
      copypaths(path_so_farl, path_so_far, mazegrid);
      findpaths(mazegrid, i, j-1, path_so_farl, required_len-1);
    }
  }
  if (i < mazegrid->mgrid_nrows-1)
  {
    if (path_so_far[i+1][j] != 1 && mazegrid->mgrid_cells[i+1][j] > 0)
    {
      copypaths(path_so_farb, path_so_far, mazegrid);
      findpaths(mazegrid, i+1, j, path_so_farb, required_len-1);
    }

  }
  if (j < mazegrid->mgrid_ncols-1)
  {
    if (path_so_far[i][j+1] != 1 && mazegrid->mgrid_cells[i][j+1] > 0)
    {
      copypaths(path_so_farr, path_so_far, mazegrid);
      findpaths(mazegrid, i, j+1, path_so_farr, required_len-1);
    }

  }

  return 0;
}

int init_path(mgrid *mazegrid, int path_so_far[][10])
{
  int i = 0, j = 0;
  for (i = 0; i < mazegrid->mgrid_nrows; i++)
  {
    for (j = 0; j < mazegrid->mgrid_ncols; j++)
    {
      path_so_far[i][j] = 0;
    }
  }

  return 0;
}

int calcpath(mgrid *mazegrid, int i, int j, int len)
{
  if (len > mazegrid->mgrid_alivecells)
  {
    printf("dead end i %u j %u len %u\n", i, j, len);
    return 1;
  }

  if (i > 0 && mazegrid->mgrid_cells[i-1][j] > 0)
  {
    mazegrid->mgrid_celldata[i-1][j].paths_from_below++;
    mazegrid->mgrid_celldata[i-1][j].paths_from_below_len[len+1]++;
    calcpath(mazegrid, i-1, j, len+1);
  }
  if (j > 0)
  {
    mazegrid->mgrid_celldata[i][j-1].paths_from_right++;
    mazegrid->mgrid_celldata[i][j-1].paths_from_right_len[len+1]++;
    calcpath(mazegrid, i, j-1, len+1);
  }
  if (i < mazegrid->mgrid_nrows-1)
  {
    mazegrid->mgrid_celldata[i+1][j].paths_from_above++;
    mazegrid->mgrid_celldata[i+1][j].paths_from_above_len[len+1]++;
    calcpath(mazegrid, i+1, j, len+1);
  }
  if (j < mazegrid->mgrid_ncols-1)
  {
    mazegrid->mgrid_celldata[i][j+1].paths_from_left++;
    mazegrid->mgrid_celldata[i][j+1].paths_from_left_len[len+1]++;
    calcpath(mazegrid, i, j+1, len+1);
  }

  return 0;
}
int main()
{
  mgrid mazegrid;
  int path_so_far[10][10];
  int required_len = 0;

  parsefile(&mazegrid);
  printgrid(&mazegrid);
  if (validategrid(&mazegrid))
  {
    printf("invalid grid\n");
    exit(0);
  }

  /* init_cells(&mazegrid);
  path_so_far[0][0] = 1;
  required_len = mazegrid.mgrid_alivecells;

  init_path(&mazegrid, path_so_far);

  findpaths(&mazegrid, 0, 0, path_so_far, required_len); */

  init_cells(&mazegrid);
  calcpath(&mazegrid, 7, 0, 0);

  printf("startxy %u endxy %u alivecells %u\n",
         mazegrid.mgrid_startxy, mazegrid.mgrid_endxy,
         mazegrid.mgrid_alivecells);

  return 0;
}
