# Hashes a file, ignoring all whitespace and comments. Use for
# verifying that code was correctly typed.
cpp -dD -P -fpreprocessed | tr -d '[:space:]'| md5sum |cut -c-6
# Usage: checkhash a (hashes a.cpp, ignoring whitespace/comments)
checkhash(){ cpp -dD -P -fpreprocessed < "$1.cpp" | tr -d '[:space:]' | md5sum | cut -c-6; }