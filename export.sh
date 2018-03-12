#!/bin/bash
if [ "$1" = "-z" ]; then
    zip -r ./space_invaders_ArtemG_DanielA . -x \*.o \*.git\* \*.vscode\* \*.DS_Store
elif [ "$1" = "-g" ]; then
    git archive -o ./space_invaders_ArtemG_DanielA.zip HEAD
else
    echo "usage: export.sh [arg];"
    echo "       -z = zip using zip"
    echo "       -g = zip using git archive"
fi
