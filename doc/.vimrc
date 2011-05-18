"set mouse=a
"set nofen
"set fdl=0
set backup
set cino=(0
set autoindent
set smartindent
set showmatch
set incsearch
set ruler
cmap w!! %!sudo tee > /dev/null %

filetype plugin on
set ofu=syntaxcomplete#Complete

set showcmd
set ignorecase
set wildmenu

"filetype plugin on

autocmd FileType c,cpp,pl,py,h setlocal tabstop=2 softtabstop=2 shiftwidth=2 cindent expandtab textwidth=76
"autocmd FileType python set
set nu
set noai
"set syntax on
"set tabstop=2

set whichwrap=
set backspace=2
set vb t_vb=
hi Search term=reverse ctermfg=black ctermbg=green
colorscheme vibrantink

set statusline=%<\ %n:%f\ %m%r%y%=%-35.(line:\ %l\ of\ %L,\ col:\ %c%V\ (%P)%)
set laststatus=2
highlight OverLength ctermbg=red ctermfg=white guibg=#592929

" Tell vim to remember certain things when we exit
"  '10 : marks will be remembered for up to 10 previously edited files
"  "100 : will save up to 100 lines for each register
"  :20 : up to 20 lines of command-line history will be remembered
"  % : saves and restores the buffer list
"  n... : where to save the viminfo files
set viminfo='10,\"100,:20,%,n~/.viminfo
set hlsearch
highlight Pmenu ctermbg=238 gui=bold
