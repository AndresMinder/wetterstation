// This File includes the command line interface (cli) to interact with the station and making configurations and other settings.

#include <Arduino.h>
#include "CLI.h"
#include "Anemometer.h"
#include "SDCard.h"

#define INDEX_CLI 100

String command_help = "help\r";
String command_config = "config\r";
String command_exit = "exit\r";
String command_show = "show\r";
String show_sdCardInfo = "sd card informations\r";

void initCLI()
{	
	Serial.println("*************************");
	Serial.println("Authorized Access Only !!");
	Serial.println("*************************");
	for (int i = 0; i < 5; i++)
	{
		Serial.println();
	}
	while (1)
	{
		Serial.println("Password:");		
		String buffer = read_string_cli();
		if (buffer.equals("asdf\r"))
		{
			Serial.println("Successfully logged in..");
			break;
		} 
		else
		{
			Serial.println("False");
			continue;
		}
	}
	for (int i = 0; i < 5; i++)
	{
		Serial.println();
	}
}

void commandLineInterface()
{
	Serial.println("\n\rUser Mode:");
	
	String buffer = read_string_cli();
	if (buffer.equals(command_help))
	{
		Serial.println("\n\rAvailable commands for this prompt:\n\r - show\r\n - config (to enter the configuration mode)\n\r");
	}
	else if (buffer.equals(command_show))
	{
		Serial.println("\n\rShow Mode:");
		Serial.println(" - sd card informations\n\r");
		while (1)
		{
			buffer = read_string_cli();
			if (buffer.equals(show_sdCardInfo))
			{
				getCardInformations();
				Serial.println("");
				readFileSDCard("data.txt");
				continue;
			}
			else if (buffer.equals(command_help))
			{
				Serial.println("\n\rAvailable commands for this prompt:\n\r - exit\n\r");
			}
			else if (buffer.equals(command_exit))
			{
				break;
			}
			else
			{
				Serial.println("***Unknown command, enter 'help' for more informations!***");
				continue;				
			}
		}
	}
	else if (buffer.equals(command_config))
	{
		Serial.println("\n\rConfiguration Mode:");
		while (1)
		{
			buffer = read_string_cli();
			if (buffer.equals(command_help))
			{
				Serial.println("\n\rAvailable commands for this prompt:\n\r - set\n\r - delete\n\r - exit (get back to user mode)\n\r");
				continue;
			}
			else if (buffer.equals(command_exit))
			{
				break;
			}
			else
			{
				Serial.println("***Unknown command, enter 'help' for more informations!***");
				continue;
			}
		}		
	}
	else
	{
		Serial.println("***Unknown command, enter 'help' for more informations!***");
	}
}

String read_string_cli()
{
	char buffer_char[INDEX_CLI];
	Serial.print('>');
	for (int i = 0; i < INDEX_CLI; i++)
	{
		while (!Serial.available()){}
		buffer_char[i] = Serial.read();
		if (buffer_char[i] == '\r')						// if carriage return
		{
			buffer_char[i+1] = '\0';
			Serial.println();
			break;
		}
		else
		{
			Serial.print(buffer_char[i]);
		}
	}
	String buffer_string(buffer_char);					// cast from char array to string
	
	return buffer_string;
}