# Encrypted-Chat

import java.security.MessageDigest;
//NEWCODE. Added function bytesToHex. It converts the bytes to a hex string

private static String bytesToHex(byte[] bytes) {
        StringBuffer result = new StringBuffer();
        for (byte b : bytes)
            result.append(Integer.toString((b & 0xff) + 0x100, 16).substring(1));
            return result.toString();
    }
    
    
    
    
    //actions that occur when connect button is pressed 
    private void msg_connActionPerformed(java.awt.event.ActionEvent evt) {                                         
        
        //while not connected to the socket
        if(connected == false)
        {
            //get the username from the username field 
            user = msg_user.getText();
            msg_user.setEditable(false);
           
            password = msg_pass.getText(); 
            
            try {
                //FIXME
                //creates message digest
                MessageDigest md = MessageDigest.getInstance("SHA-256");
                md.update(password.getBytes());
                //uses message digest as key for encryption
                 td.TripleDes(bytesToHex(md.digest()));
            } catch (Exception ex) {
                Logger.getLogger(client.class.getName()).log(Level.SEVERE, null, ex);
            }
            
