filename=$1
outputname=$2
N=$(wc -l < "$filename")
awk -v N=$N -F, '
    BEGIN{OFS=""} 
{
    if(NR==1){
    print "{ \n \"pokedex\":["
        for(i=1;i<=NF;i++)
            f[i] = $i;
    }
    if(NR != 1) {
    print "  {"
        for(j=1;j<=NF;j++) {
            if (j != NF) {
                if ($j ~ /^[0-9]+$/) {
                    print "   \""f[j]"\"" ":",$j",";
                } else {
                    print "   \""f[j]"\"" ":\"",$j"\",";
                }
            } else {
                if ($j ~ /^[0-9]+$/) {
                    print "   \""f[j]"\"" ":",$j;
                } else {
                    print "   \""f[j]"\"" ":\"",$j"\"";
                }
            }
        }
        if(NR != N){
        print "  },"
        }
        else{
        print "  }"
        }
    }
} END { print "]\n}"; }
' $filename > $outputname