
#developing 'forward chechking' filter applied on domain


import input
import graph_basic


def forwardChecking(domain, inputSudoku, graph):
    domain = domain.copy()
    for i in range(1, 82, 1):
        if inputSudoku[i] != 0:
            domain[i] = [inputSudoku[i]]
            continue
        for node in graph[i]:
            dom = domain[node].copy()
            dom2 = domain[i].copy()   #culprit!!!    if we don't use it then we will in truble
            for d in domain[i]:
                if d in dom:
                    dom.remove(d)
                    if len(dom) == 0:
                        dom2.remove(d)
                        #domain[i].remove(d)
                    dom = domain[node].copy()
            domain[i] = dom2.copy()

    return domain
