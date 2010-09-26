/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package io;

import gnu.io.SerialPort;
import gnu.io.SerialPortEvent;
import gnu.io.SerialPortEventListener;
import java.io.IOException;
import java.io.InputStream;
import java.util.TooManyListenersException;

/**
 *
 * @author victor
 */
public class ReadSerial implements SerialPortEventListener {

    public ReadSerial() {
        this.dataReadBuffer = new String();
        this.dataAvailable = false;
    }

    public boolean isDataAvailable() {
        return this.dataAvailable;
    }

    public String getDataReadBuffer() {
       this.dataAvailable = false;
        return dataReadBuffer;
    }


    public void run(SerialPort serialPort) {
        try {
            this.serialPort = serialPort;
            //Pega o InputStream da Porta Serial
            inputStream = serialPort.getInputStream();
            //Cria um novo Listener de Eventos
            serialPort.addEventListener(this);
            //Avisa se tive alguma mudança na Porta Serial
            serialPort.notifyOnDataAvailable(true);
        } catch (IOException e) {
            e.printStackTrace();
        } catch (TooManyListenersException ex) {
            ex.printStackTrace();
        }

    }

    public void serialEvent(SerialPortEvent event) {

        StringBuffer readBuffer = new StringBuffer();
        int numBytes = 0;
        dataAvailable = false;
        
        switch (event.getEventType()) {
            case SerialPortEvent.BI:
            case SerialPortEvent.OE:
            case SerialPortEvent.FE:
            case SerialPortEvent.PE:
            case SerialPortEvent.CD:
            case SerialPortEvent.CTS:
            case SerialPortEvent.DSR:
            case SerialPortEvent.RI:
            case SerialPortEvent.OUTPUT_BUFFER_EMPTY:
                break;
            case SerialPortEvent.DATA_AVAILABLE:

                // enquanto não vem o fim de comando
                while (numBytes != '\r') {
                    try {
                        numBytes = inputStream.read();
                        if (numBytes == -1) {
                            System.out.println("numBytes = -1");
                            break;
                        }else {
                            //System.out.println("numBytes = " + (char)numBytes);
                            readBuffer.append((char) numBytes);
                        }
                    } catch (IOException ioe) {
                        System.out.println("Serial read error:"  + ioe);
                        dataAvailable = false;
                    }
                }
                dataReadBuffer = new String(readBuffer);
                dataAvailable = true;
                //System.out.println(readBuffer);
                break;
        }
    }

    // Atributos da classe
    private SerialPort serialPort;
    private InputStream inputStream;
    private boolean dataAvailable;
    private String dataReadBuffer;
}
