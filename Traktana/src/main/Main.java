package main;


import Interface.ConfigSerialDialog;
import Interface.MainWindow;
import device.TraktanaDebug;
import gnu.io.SerialPort;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author victor
 */
public class Main {

    public Main(){
        Config = new ParametersConfig();
        // Serial Configuration: default init
        Config.getSerialconfig0().setPortName("/dev/ttyUSB0");
        Config.getSerialconfig1().setPortName("/dev/ttyUSB1");
        
    }

    public void setConfig(ParametersConfig Config) {
        this.Config = Config;
    }

    public ParametersConfig getConfig() {
        return Config;
    }

    public void connectSerialPort0(){

    }
    public void connectSerialPort1(){

    }
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here        
    }

    // Variables declaration
    
    // Serial Configuration parameters
    private ParametersConfig Config;
    
    private TraktanaDebug trakdebug;
}
