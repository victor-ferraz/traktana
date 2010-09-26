package main;


import device.Traktana;

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
        config = new ParametersConfig();
        // Serial Configuration: default init
        config.getSerialConfigDevice().setPortName("/dev/ttyUSB0");
        config.getSerialConfigDebug().setPortName("/dev/ttyUSB1");
        traktana= new Traktana(config.getSerialConfigDevice(),config.getSerialConfigDebug());
    }

    public void setConfig(ParametersConfig Config) {
        this.config = Config;
    }

    public ParametersConfig getConfig() {
        return config;
    }

    public boolean connectDevice(){
        traktana.setSerialParametersDevice(config.getSerialConfigDevice());
        return traktana.connectDevice();
    }
    public boolean connectDebug(){
        traktana.setSerialParametersDebug(config.getSerialConfigDebug());
        return traktana.connectDebug();
    }
    public void disconnectDevice(){
        traktana.disconnectDevice();
    }
    public void disconnectDebug(){
        traktana.disconnectDebug();
    }
    public boolean getDeviceConnected(){
        return traktana.deviceConnected;
    }
    public boolean getDebugConnected() {
        return traktana.debugConnected;
    }

    public void readConfiguration() {
        traktana.readConfiguration();
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here        
    }

    // Variables declaration
    
    // Serial Configuration parameters
    private ParametersConfig config;
    private Traktana traktana;
}
