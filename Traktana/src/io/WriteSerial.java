/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package io;

import gnu.io.SerialPort;
import java.io.IOException;
import java.io.OutputStream;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author victor
 */
public class WriteSerial {

    public WriteSerial() {
        started = false;
    }
    public void run(SerialPort serialPort){
        try {
            this.serialPort = serialPort;
            outputStream = serialPort.getOutputStream();
            started = true;
        } catch (IOException ex) {
            Logger.getLogger(WriteSerial.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    public boolean sendString(String str){
        boolean ret = false;
        try {
            outputStream.write(str.getBytes());
            ret = true;
        } catch (IOException ex) {
            Logger.getLogger(WriteSerial.class.getName()).log(Level.SEVERE, null, ex);
        }
        return ret;
    }
    public boolean sendChar(char ch){
        boolean ret = false;
        try {
            outputStream.write(ch);
            ret = true;
        } catch (IOException ex) {
            Logger.getLogger(WriteSerial.class.getName()).log(Level.SEVERE, null, ex);
        }
        return ret;
    }
    public void sendBreak(){
        serialPort.sendBreak(1);
    }

    private SerialPort serialPort;
    private OutputStream outputStream;
    private boolean started;
}
