,		Read c0
> ,	     	Read c1
> ++++ ++++  	Add 8 to c2
[Start loop
< ---- --	Substract 7 to c1
< ---- --	Substract 7 to c0
>> -   		Substract 1 to c2
]
<		Go to c1
[		Start loop
<		Go to c0
[		Start loop
		      >> +	Add 1 to c2
		      > +	Add 1 to c3
		<<< -Substract 1 to c0
]
>>		Go to c2
[		Start loop
		      << +	Add 1 to c0
		      >> -Substract 1 to c2
]
< -		Substract 1 to c1
]
++++ ++++	Add 8 to c1
[    		Start loop
>> ++++ ++	Add 6 to c3
<< -		Substract 1 to c1
]
>> .		Move to c3 and print the result	