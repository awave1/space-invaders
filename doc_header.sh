#!/bin/bash
if [ -z $1 ]; then
    echo "missing filepath in format \"../*.h\" (with quotation marks)"
else
    for file in $1; do
        echo "$file"
        FILENAME=$(basename "$file")
        sed -i '1i \/*\n *  File: '$FILENAME' \n *  Authors: Artem Golovin, Daniel Artuso \n *\/\n' "$file"
    done
fi
