public test{

	private int number1 = 1223_776_998;
	//not to be recognised
	private int number2 = _122_334;

	/************documentation*****************/
	private int number3 = 0554_776_332;
	private int number4 = 0_665_8857;

	//hexadecimal num
	private int number5 = 0x77764_7746_665;
	private int number6 = 0x_776_7765;

	//decimal
	private float number7 = 1223_6665_.;
	private float number8 = 1223_6664._77736_E_7746;

	//hexadecimal
	private float number9 = 0x55_5.77_446p5_545;
	private float number10 = 0x55_6.7_665P77_66;

	//binary
	private int number11 = 0b7664_7756;
	private int number12 = 0b776.776E667;

	private String str1 = "Space oddity \b \n \r \f \u002A \t \" \' \\ \066 \2 \24; ; ";

	private bool b = (number1 == number2)^(number2>number3)||(number5>=number10)&(number6!=number7)||(number5*number2 == number6/number5);

}
