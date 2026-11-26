alias c='g++ -Wall -Wconversion -Wfatal-errors -g -std=c++17 \
	-fsanitize=undefined,address'
xmodmap -e 'clear lock' -e 'keycode 66=less greater' #caps = <>
# Usage: run a (compiles a.cpp, reads input.txt, writes output.txt)
run(){ g++ -std=gnu++23 -O2 -Wall -Wextra "$1.cpp" -o "$1" && ./"$1" < input.txt | tee output.txt; }
# Usage: debug a (detects overflow, out-of-bounds, UB)
debug(){
    g++ -std=gnu++23 -g -Wall -Wextra -Wshadow \
    -fsanitize=address,undefined \
    -fno-sanitize-recover=all -D_GLIBCXX_DEBUG \
    "$1.cpp" -o "$1" &&
    ./"$1" < input.txt | tee output.txt
}