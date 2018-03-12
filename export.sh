#!/bin/bash
FILENAME=""
if [ -z "$2" ]; then
    FILENAME="space_invaders_ArtemG_DanielA"
else
    FILENAME="$2"
fi

if [ "$1" = "-z" ]; then
    zip -r ./"$FILENAME" . -x \*.o \*.git\* \*.vscode\* \*.DS_Store
elif [ "$1" = "-g" ]; then
    git archive -o ./$FILENAME.zip HEAD
else
    echo "usage: export.sh [arg] [filename];"
    echo "       -z = zip using zip"
    echo "       -g = zip using git archive"
fi
