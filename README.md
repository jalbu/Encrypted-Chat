# Encrypted-Chat

import java.security.MessageDigest;


This is what I added under private void msg_connActionPerfommed

private void msg_connActionPerformed(java.awt.event.ActionEvent evt) {                                         
        //while not connected to the socket
        if(connected == false)
        {
            //get the username from the username field 
            user = msg_user.getText();
            msg_user.setEditable(false);
           
            password = msg_pass.getText();
            MessageDigest md = MessageDigest.getInstance("SHA-256");
            md.update(password.getBytes());
            
            //converts byte to hex format
            StringBuffer hexString = new StringBuffer();
            for(int i = 0; i < byteData.length; i++)
            {  String hex = Integer.toHexString(0xff & byteData[i]);
               if(hex.length() == 1) hexString.append('0');
               hexString.append(hex);
            }
            }
