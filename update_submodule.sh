#!/bin/bash

# Ottieni l'elenco dei branch git nel repository attuale
branches=$(git branch --list | cut -c 3-)

# Cicla attraverso ogni branch
for branch in $branches; do
    # Passa al branch corrente
    git switch $branch
    
    # Aggiungi il file "hmt_hal" alla staging area
    git add hmt_hal
    
    # Esegui il commit con il messaggio specificato
    git commit -m "Aggiornato submodule"
    
    # Esegui il push del branch corrente
    git push origin $branch
done