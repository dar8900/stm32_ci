#!/bin/bash

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
  # Passa al branch corrente
  git switch $branch
  
  # Esegui il cherry-pick della commit specificata
  git cherry-pick $commit

  git push origin $branch
done

