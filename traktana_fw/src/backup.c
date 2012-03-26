void process_cmd(void)
{
	char goodcmd[]	= "- Command Accepted.\n\n\r\0";
	char evilcmd[]	= "- BAD Command.\n\n\r\0";

	char *r = evilcmd;

	if (cmdissued == 1)
	{
		switch(*rbufptr++)
		{
		/*** STEPPER COMMANDS ***/
			case 's':
				putcUART1('s');
				if(*rbufptr++ == 't'){
					putcUART1('t');
					switch(*rbufptr++){
						case 's':{
							putcUART1('s');
							putcUART1(' ');
							// sts command received (start)
							if(*rbufptr++ == ' '){
								// sts parameters [1 or 2]
								if(*rbufptr == '1'){
									r = goodcmd;stepper_enable1=1;
								}else if(*rbufptr++ == '2'){
									r = goodcmd;stepper_enable2=1;
								}	
							}
						}break;
						case 'p':{
							putcUART1('p');
							// stp command received (stop)
							if(*rbufptr++ == ' '){
								// stp parameters [1 or 2]
								if(*rbufptr == '1'){
									r = goodcmd;stepper_enable1=0;
								}else if(*rbufptr++ == '2'){
									r = goodcmd;stepper_enable2=0;
								}	
							}
						}break;
						case 'd':{
							putcUART1('d');
							// std command received (disable)
							if(*rbufptr == ' '){
								*rbufptr++;
								// std parameters [1 or 2]
								if(*rbufptr == '1'){
									r = goodcmd;disable_stepper1();
								}else if(*rbufptr++ == '2'){
									r = goodcmd;disable_stepper2();
								}	
							}else{
								switch(*rbufptr++){
									// stdc command received (direction clockwise)
									case 'c':{
									 if(*rbufptr++ == ' '){
										// stdc parameters [1 or 2]
										if(*rbufptr == '1'){
											r = goodcmd;direction1=1;
										}else if(*rbufptr++ == '2'){
											r = goodcmd;direction2=1;
										}
									 }
									}break;	
									// stdh command received (direction counter clockwise)
									case 'h':{
									 if(*rbufptr++ == ' '){
										// stdh parameters [1 or 2]
										if(*rbufptr == '1'){
											r = goodcmd;direction1=0;
										}else if(*rbufptr++ == '2'){
											r = goodcmd;direction2=0;
										}
									 }
									}break;	
								}
							}
						}break;
						case 'm':{
							putcUART1('m');
								switch(*rbufptr++){
									// stmf command received (Full Step Mode)
									case 'f':{
									 if(*rbufptr++ == ' '){
										// stdc parameters [1 or 2]
										if(*rbufptr == '1'){
											r = goodcmd;mode_step1=1;
										}else if(*rbufptr++ == '2'){
											r = goodcmd;mode_step2=1;
										}
									 }
									}break;	
									// stmh command received (Half Step Mode)
									case 'h':{
									 if(*rbufptr++ == ' '){
										// stdh parameters [1 or 2]
										if(*rbufptr == '1'){
											r = goodcmd;mode_step1=0;
										}else if(*rbufptr++ == '2'){
											r = goodcmd;mode_step2=0;
										}
									 }
									}break;	
								}
						}break;
						case 'f':{
							putcUART1('f');
							r = goodcmd;
						}break;
						// invalid command
						default: r = evilcmd;break;
					}
				}
			break;
			/*** DC MOTOR COMMANDS ***/
			case 'm':
				putcUART1('m');
				if(*rbufptr++ == 'd'){
					putcUART1('d');
					if(*rbufptr++ == 'c'){
						putcUART1('c');
						switch(*rbufptr++){
							case 'r':{
								putcUART1('r');
								// mdcr command received (start)
								if(*rbufptr++ == ' '){
									// mdcr parameters []
									r = goodcmd; SetDCOC1PWM(*rbufptr);
								}
							}break;
							case 'p':{
								putcUART1('p');
								// mdcp command received (start)
								if(*rbufptr++ == ' '){
									// mdcp parameters []
									
								}
							}break;
							case 'i':{
								putcUART1('i');
								// mdci command received (start)
								if(*rbufptr++ == ' '){
									// mdci parameters []
									
								}
							}break;
							case 'd':{
								putcUART1('d');
								// mdcd command received (start)
								if(*rbufptr++ == ' '){
									// mdcd parameters []
									
								}
							}break;
						}
					}
				}
			break;
		}

		rbufptr	= (char*)bufstt;
		wbufptr = rbufptr;

		putsUART1((unsigned int *)r);
		while(BusyUART1());

		cmdissued = 0;
	}
}
