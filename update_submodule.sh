#!/bin/bash

ACTUAL_BRANCH=$(git rev-parse --abbrev-ref HEAD)
# Ottieni l'elenco dei branch git nel repository attuale
branches=$(git branch --list | cut -c 3-)

# Cicla attraverso ogni branch
for branch in $branches; do
    # Passa al branch corrente
    git switch $branch
    
    # Aggiungi il file "hmt_hal" alla staging area
    git add hmt_hal boards_stm32
    
    # Esegui il commit con il messaggio specificato
    git commit -m "Aggiornato submodule"
    
    # Esegui il push del branch corrente
    git push origin $branch
done

git switch "$ACTUAL_BRANCH"
