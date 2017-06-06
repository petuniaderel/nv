diff nvml.h nvml_375_66.h >diff.h
cat diff.h |grep -e "^>.*"|grep -v -e "^>  \*.*" -e "^> /\*\*.*"  >> nvml_375_66.c
