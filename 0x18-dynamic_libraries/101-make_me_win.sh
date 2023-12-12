#!/bin/bash
echo -e '#include <stdio.h>\n#include <stdlib.h>\n#include <time.h>\n\nint rand(void) { return 9; }' > /tmp/winner.c && gcc -shared -fPIC -o /tmp/winner.so /tmp/winner.c && LD_PRELOAD=/tmp/winner.so
