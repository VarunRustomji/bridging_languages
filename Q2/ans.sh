#!/bin/bash

CASE=""

while [[ "$1" != "" ]]; do
    case $1 in
        -c | -case )         
		shift
		CASE="$1"
                ;;
    esac
    shift
done

case $CASE in
	snake_case)
		runhaskell convert.hs
		;;
	kebab-case)
		runhaskell kebab.hs
		;;
	camelCase)
		python camel.py
		;;
	PascalCase)
		python pascal.py
		;;
esac
