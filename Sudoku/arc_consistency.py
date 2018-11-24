
#developing the 'arc consistency' filtering for more reduction of domain

import input
import graph_basic


def arcConsistency(domain, inputSudoku, graph):
    domain = domain.copy()
    for i in range(1, 82, 1):
        if inputSudoku[i] != 0:
            domain[i] = [inputSudoku[i]]
            #continue           #no continue here, this is the basic difference with forwardChecking
        nodes = graph[i]
        for node in nodes:
            parentDomain = domain[i].copy()
            dom2 = domain[node].copy()   #i think its culprit too just like in forwardChecking
            for cd in domain[node]:
                if cd in parentDomain:
                    parentDomain.remove(cd)
                    if len(parentDomain) == 0:
                        dom2.remove(cd)
                    parentDomain = domain[i].copy()
            domain[node] = dom2.copy()
    return domain
