			c0 = 0
> ++++ ++++		c1 = 8
[			Start loop
< ++++ ++++ +		Add 9 to c0
> -    	    		Subtract 1 from c1
]
< .			Translates the c0 value 72 to "H"
> +++	       	  	c1 = 3
[ 			Start loop
< ++++ ++++ ++++ +	Add 13 to c0
> -    	    	 	Subtract 1 from c1
]
< .		        Translates the c0 value 111 to "o"
---	       	  	Substract 3 from c0
.			Translates the c0 value 108 to "l"
> ++			c1 = 2
[ 			Start loop
< ---- -	        Substract 5 to c0
> -    			Subtract 1 from c1
]
< .			Translates the c0 value 98 to "b"
+++			Add 3 to c0
.			Translates the c0 value 101 to "e"
> +++	       	  	c1 = 3
[ 			Start loop
< ++++			Add 4 to c0
> -			Subtract 1 from c1
]
< +			Add 1 to c0
.       	     	Translates the c0 value 114 to "r"
++	       	  	Add 2 to c0
.			Translates the c0 value 116 to "t"
---- -			Substract 5 from c0
.    			Translates the c0 value 111 to "o"
-			Substract 1 from c0
.			Translates the c0 value 110 to "n"
> ++++ ++++ ++		Add 10 to c1
[      	    		Start loop
< ---- ---- ---		Substract 11 from c0
> -   		      	Subtract 1 from c1
]
< +++++ +++++		Add 10 to c0
. 			Translates the c0 value 0 to "\0"