/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package io;

import gnu.io.CommPortIdentifier;
import java.util.ArrayList;

/**
 *
 * @author victor
 */
public class SerialInterface {

    public SerialInterface() {
    
    }

    public boolean sendCommand(){
        boolean response = false;
        
        
        return response;
    }
    
    public void receiveResponse(){
        
    }

    public static String[] listPorts(){
        java.util.Enumeration<CommPortIdentifier> portEnum = CommPortIdentifier.getPortIdentifiers();
        ArrayList portlist = new ArrayList();
        while ( portEnum.hasMoreElements() )
        {
            CommPortIdentifier portIdentifier = portEnum.nextElement();
            portlist.add(portIdentifier.getName());
            //System.out.println(portIdentifier.getName()  +  " - " +  portIdentifier.getPortType());
        }
        String ports[] = new String[portlist.size()];
        for(int i = 0 ; i < ports.length ; i++){
               ports[i] = (String) portlist.get(i);
        }
        return ports;
    }

}
