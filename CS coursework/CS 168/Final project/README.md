Packages required: matplotlib, numpy, csv, tensorflow, keras, ot, torch

Code files:
sinkhorn.py: Contains implementation of Sinkhorn's algorithm along with all 
experiments. To replicate any of the experiments, type the function call into 
main().

runtime.py: Contains code for parsing through results and generating graphs 
in the Graphics folder. To replicate any of the plots, type the function
call into main().

wasser_bary.py: Implementation of example using Wasserstein barycenters. The 
extra files are not included here, but the GitHub repo used for this can be 
accessed here:
https://github.com/eddardd/wasserstein-barycenters

My example is a near copy of their implementation in the package. I used the same
cost function and similar functions for simplicity.

wdl.py: Contains code for Wasserstein Dictionary Learning. All WDL code beyond
function calls has been removed as the code behind it is currently being used
for research and is unpublished. The code present generates the plots included 
in the paper.

Graphics: Contains any figures or pictures that I generated. Most were used.

Other files:
time.txt, time2.txt, time3.txt, and time4.txt: files that store different 
iterations of run time comparisons. Was me trying different things, time4 should
be for lambda = 12. 

res.txt, and res2.txt: Distance and relative error comparisons for varying 
values of lambda. res.txt specifically contains results for what is seen in 
box plot, so lambda = 64. res2.txt contains the higher values that result in 
NAN. 

data.pt: data used for WDL example. 

