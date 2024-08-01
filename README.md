# t-channel_dark_QCD
UFO files for a QCD like dark sector with and t-channel mediator

This repository contains model files for the generation of semi-visible and/or emerging jets via a t-channel mediator. UFO files given for Yukawa-like couplings to up-type and down type-quarks. Feynrule files and an example notebook to create the UFO files are provided. For details on the models see e.g. [1502.05409](https://inspirehep.net/literature/1345350), [2011.13990](https://inspirehep.net/literature/1834020),  2409.XXXX. For the model files degenerate dark quark masses are assumed. Three dark quarks generations are implemented, though additional dark quarks can be added analogously in the feynrule models. Showering and hadronization can be performed using the pythia HiddenValley. Example pythia files are given. 

## couplings to down-type quarks
A t-channel mediator facilitating Yukawa-like couplings between SM down-type quarks and three generations of dark quarks are implemented. Bi-fundamental mediator is labeled `x` the dark quarks `ddark1, ddark2, ddark2` with their antiparticles being `x~, ddark1~, ddark2~, ddark3~`.

The `param_card.dat` generated by madgraph will have a fixed width set for the mediator, which may not be desired. The `param_card.dat` can be manually modified to 

`DECAY 490001 Auto`

Similarily, the masses of the mediator and dark quarks can be set in the `param_card.dat`

`4900001 1.000000e+02 # massx`

`4900101 1.000000e+01 # mdarkq1`

`4900102 1.000000e+01 # mdarkq2`

`4900103 1.000000e+01 # mdarkq3`

## couplings to up-type quarks
The same labels as for the couplings to down-type quarks are used for couplings to up-type quarks. Again, the mediator width  and the masses can be manually set in the `param_card.dat` using 

`DECAY 490002 Auto`

`4900002 1.000000e+02 # massx`

`4900101 1.000000e+01 # mdarkq1`

`4900102 1.000000e+01 # mdarkq2`

`4900103 1.000000e+01 # mdarkq3`

Note, the different PDG ID of the mediator, while the PDG IDs of the dark quarks is the same as for the case of couplings to down-type quarks.  

## Example madgraph event generation

-mediator pair production for couplings to down-type quarks

`import model darkQCD_fv_down`

`generate p p > x x~`

`output mediator_pair_down`

-dark quark production via t-channel mediator exchange for couplings to up-type quarks

`import model darkQCD_fv_up`

`define qd = ddark1 ddark1~ ddark2 ddark2~ ddark3 ddark3~`

`generate p p > qd qd`

`add process p p > qd qd j`

`add process p p > qd qd j j`

`output t_channel_dark_quarks_up`


## Notes on using pythia for showering and hadronization
The pythia HiddenValley module can be used for showering and hadronization of the dark sector. The PDG IDs in the UFO files are set so that they correspond to the ones of the HiddenValley module. In pythia the model details are set by 

`HiddenValley:Ngauge = 3           ! # of dark QCD colours`

`HiddenValley:nFlav = 4				     ! # flavours used for the running!`

`HiddenValley:separateFlav = on	   ! allow seperate properties for dark quarks and pions`

`HiddenValley:Lambda=40						 ! confinement scale as used by pythia`

`HiddenValley:pTminFSR = 44.0			 ! Lowest Alllowed pT of Emission. IMPORTANT: pTminFSR > Lambda, >, not =>`

If desired the mediator masses and dark quark masses can be manually changed from their madgraph values:


`4900001:m0 = 2000`

`4900101:m0 = 2`

`4900102:m0 = 2`

`4900103:m0 = 2`

The mediator decays are set as 

`4900001:oneChannel on 0.111 103 1  4900101`

`4900001:addChannel on 0.111 103 3  4900101`

`4900001:addChannel on 0.111 103 5  4900101`

`4900001:addChannel on 0.111 103 1  4900102`

`4900001:addChannel on 0.111 103 3  4900102`

`4900001:addChannel on 0.111 103 5  4900102`

`4900001:addChannel on 0.111 103 1  4900103`

`4900001:addChannel on 0.111 103 3  4900103`

`4900001:addChannel on 0.111 103 5  4900103`

In the in 2409.XXXX described scenario fourth and higher generation dark quarks are only produced in the shower as they don't couple to SM quarks. In pythia their masses are set in the same way as the first three generations. The PDG IDs for higher generation dark quarks are `490010i` with `i = 4, 5, ...8`.  

In addition, dark meson masses, lifetimes and branching ratios can be set in pythia. These are model dependent and it is recommended to set up a script to calculate them for a model and parameter choice. An example with four dark flavours is given.






