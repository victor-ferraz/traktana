/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package io;

import gnu.io.CommPortIdentifier;
import gnu.io.PortInUseException;
import gnu.io.SerialPort;
import gnu.io.UnsupportedCommOperationException;
import java.util.ArrayList;
import java.util.Enumeration;
import main.ParametersSerial;

/**
 *
 * @author victor
 */
public class SerialInterface {

    public SerialInterface(ParametersSerial paramConfig) {
        this.paramConfig = paramConfig;
        serialConnected = false;
        portRead = new ReadSerial();
    }

    public void setParamConfig(ParametersSerial paramConfig) {
        if(serialConnected){
            disconnect();
        }
        this.paramConfig = paramConfig;
    }

    public ParametersSerial getParamConfig() {
        return paramConfig;
    }

    public boolean sendCommand() {
        boolean response = false;


        return response;
    }

    public void receiveResponse() {
        if(serialConnected){
            while(!portRead.isDataAvailable());
            System.out.println(portRead.getDataReadBuffer());
        }
    }

    public boolean connect() {
        serialConnected = false;

        //Retorna o identificador da porta
        CommPortIdentifier portId = getPortIdentifier(paramConfig.getPortName());
        //Se o PortId for nulo, não há porta disponível
        if (portId != null) {

            try {
                //Abre a porta serial solicitada
                serialPort = (SerialPort) portId.open(this.getClass().getName(), 2000);
                //Passa os parametros da porta serial
                serialPort.setSerialPortParams(paramConfig.getBaud(),
                        paramConfig.getDataBits(),
                        paramConfig.getStopBits(),
                        paramConfig.getParity());
                portRead.execute(serialPort);
                //portWrite também vai aqui
                serialConnected = true;

            } catch (PortInUseException e) {
                e.printStackTrace();
            } catch (UnsupportedCommOperationException e) {
                e.printStackTrace();
            }
        } else {
            System.out.println("Serial port unavailable");
        }
        return serialConnected;
    }

    public void disconnect(){
        try{
            serialPort.close();
        }catch(Exception e){
            System.out.println("Error closing the serial port!");
        }
    }

    public static String[] listPorts() {
        java.util.Enumeration<CommPortIdentifier> portEnum = CommPortIdentifier.getPortIdentifiers();
        ArrayList portlist = new ArrayList();
        while (portEnum.hasMoreElements()) {
            CommPortIdentifier portIdentifier = portEnum.nextElement();
            portlist.add(portIdentifier.getName());
            //System.out.println(portIdentifier.getName()  +  " - " +  portIdentifier.getPortType());
        }
        String ports[] = new String[portlist.size()];
        for (int i = 0; i < ports.length; i++) {
            ports[i] = (String) portlist.get(i);
        }
        return ports;
    }

    private CommPortIdentifier getPortIdentifier(String portName) {
        //Pega os identificadores de porta
        Enumeration portList = CommPortIdentifier.getPortIdentifiers();
        Boolean portFound = false;
        //Varre as possíveis portas
        while (portList.hasMoreElements()) {
            CommPortIdentifier portId = (CommPortIdentifier) portList.nextElement();
            //Verifica se a porta é a serial
            if (portId.getPortType() == CommPortIdentifier.PORT_SERIAL) {
                System.out.println("Available port: " + portId.getName());
                //Verifica se é o identificador correto (COM1 ou ttsy0)
                if (portId.getName().equals(portName)) {
                    System.out.println("Found port: " + portName);
                    portFound = true;
                    return portId;
                }
            }

        }

        return null;

    }

    private String getPortNameByOS() {

        String osname = System.getProperty("os.name", "").toLowerCase();
        if (osname.startsWith("windows")) {
            return "COM1"; //Se estiver no Windows
        } else if (osname.startsWith("linux")) {
            return "/dev/ttyUSB0"; //Se estiver no Linux
        } else if (osname.startsWith("mac")) {
            return "???"; //No mac eu não sei
        } else {
            System.out.println("Seu S.O. não é tem suporte ainda!"); //Se não for nenhum deles.
            System.exit(1);
            return null;
        }

    }
    // Variables
    private ParametersSerial paramConfig;
    private boolean serialConnected;
    SerialPort serialPort;
    private ReadSerial portRead;
}
