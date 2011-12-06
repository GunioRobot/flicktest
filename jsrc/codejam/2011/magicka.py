import sys
import shlex
    
def main():
    takeinput()

def parse_output(op, op_text, comb_table, oppo_table):
    if len(op_text) < 2:
        return 'false'
    
    last_two = op_text[len(op_text)-2:]
    ltstring = ""
    ltstring += last_two[0]
    ltstring += last_two[1]
    if ltstring in comb_table:
        temp = ltstring
    else:
        temp = ""
    
    
    if op_text[len(op_text)-1] in oppo_table:
        if oppo_table[op_text[len(op_text)-1]] in op:
                op = {}
                op_text = []
                return 'false'
    
    if temp in comb_table:
            #discard both ele and add comb
            
            #remove last two elements
            op_text.pop()
            op_text.pop()
            #append comb char
            op_text.append(temp) 
            return 'true'

            
def parse_input(serial_no, ip, comb_table, oppo_table):
    #print ip
    #print comb_table
    #print oppo_table
    
    skip = 'false'
    output = {}
    output_text = []
    j = 0
    i = 0
    
    while i < len(ip):
        #check for combo first
        if skip == 'true':
            skip = 'false'
            if (parse_output(output, output_text, comb_table, oppo_table) == 'true'):
                skip = 'true'
            i+=1
            continue
        
        if ip[i] in oppo_table:
            #clean output if opposite exists
            #print ip[i]
            if oppo_table[ip[i]] in output:
                output = {}
                output_text = []
                i+=1
                continue
            
        if ip[i:i+2] in comb_table:
            #discard both ele and add comb
            if comb_table[ip[i:i+2]] in output:
                output[comb_table[ip[i:i+2]]] += output[comb_table[ip[i:i+2]]]
            else:
                output[comb_table[ip[i:i+2]]] = 1
             
            output_text.append(comb_table[ip[i:i+2]]) 
            j+=1
            i+=1
            skip = 'true'
            continue
        
        if ip[i] in output:
            output[ip[i]] += output[ip[i]]
        else:
            output[ip[i]] = 1
             
        output_text.append(ip[i])
        j+=1
        i+=1

    
    k = 0
    #print output
    sys.stdout.write("Case #"+str(serial_no)+": [")
    for c in output_text:
        sys.stdout.write(c)
        if k != len(output_text)-1:
            sys.stdout.write(", ")
        k+=1
    sys.stdout.write("]\n")
    
    
        
    
def prepare_comb(comb, comb_table):
    for i in range(0, len(comb)):
        comb_table[comb[i][0:2]] = comb[i][2]
        comb_table[comb[i][0:2][::-1]] = comb[i][2]
    
    #print comb_table
         
    
def prepare_oppo(oppo, oppo_table):
    for i in range(0, len(oppo)):
        oppo_table[oppo[i][0]] = oppo[i][1]
        oppo_table[oppo[i][1]] = oppo[i][0]
        
    #print oppo_table
    
def parse_row(serial, row):
    strings = shlex.split(row)
    comb = []
    oppo = []
    ip = ""
    j = 0
    
    if int(strings[j]) > 0:
        total_comb = int(strings[j])
        for i in xrange(j+1, j+1+total_comb):
            comb.append(strings[i])
            i+=1
        
        j+=total_comb+1
    else:
        j += 1
    
    if int(strings[j]) > 0:
        total_oppo = int(strings[j])
        for i in xrange(j+1, j+1+total_oppo):
            oppo.append(strings[i])
            i+=1
        j += total_oppo+1
    else:
        j += 1
        
    if int(strings[j]) > 0:
        for i in xrange(j+1, len(strings)):
            ip = strings[i]
            i+=1
    
    comb_table = {}
    oppo_table = {}
    prepare_comb(comb, comb_table)
    prepare_oppo(oppo, oppo_table)
    
    
    parse_input(serial, ip, comb_table, oppo_table)
    
def takeinput():
    total_rows = int(raw_input())
    
    for i in xrange(0, total_rows):
        parse_row(i+1, raw_input())  
          
# This is the standard boilerplate that calls the main() function.
if __name__ == '__main__':
    main()