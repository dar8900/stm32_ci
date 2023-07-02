#!/bin/bash

ACTUAL_BRANCH=$(git rev-parse --abbrev-ref HEAD)
# Ottieni l'elenco dei branch locali
branches=$(git branch --format='%(refname:short)')

# Specifica la commit da cherry-pickare
commit=$1

if [ -z "$commit" ];then
	echo "Inserire la commit sha"
	exit 1
fi	

# Itera su ogni branch
for branch in $branches; do

  if [ "$branch" !=  "$ACTUAL_BRANCH" ]; then
    # Passa al branch corrente
    git switch $branch
    
    # Esegui il cherry-pick della commit specificata
    git cherry-pick $commit

    git push origin $branch
  fi
  
done

git switch "$ACTUAL_BRANCH"
