package com.company;
import java.lang.Math;
public class Main {

    public static void main(String[] args) {
        int result = verifyprops("aaaaaaaaaaaaaaaaaaaaa");
        System.out.println(result);
    }

    public static int verifyprops(String password) {
        int contorerrorsforpasswordbelow6 = 0;
        int contorerrorsofpasswordabove20 = 0;
        int contorok = 0;
        int minimglobal = Integer.MAX_VALUE;
        if (password.length()<6)
        {
            contorerrorsforpasswordbelow6 = (6-password.length());
            int contormissingcharacters = 3-existentcharacters(password);
            int result = casespasswordisbelow20length(password);
            int maximlocal =Math.max(Math.max(contorerrorsforpasswordbelow6,contormissingcharacters),result);
            return maximlocal;

        }
        else if (password.length()>=6 && password.length() <=20)
        {
            int missingcharacters =3-existentcharacters(password);
            int result = casespasswordisbelow20length(password);
            int maximlocal = Math.max(missingcharacters,result);
            return maximlocal;
        }
        else
        {
            contorerrorsofpasswordabove20 = (password.length()-20);
            int contormissingcharacters = 3-existentcharacters(password);
            String password3 ="";
            for (int i=0;i<password.length()-20;i++)
            {
                password3= password.substring(i,i+20);
                int result = casespasswordisbelow20length(password3);
                int maximlocal =contorerrorsofpasswordabove20 + Math.max(result,contormissingcharacters);
                if (minimglobal>maximlocal)
                {
                    minimglobal = maximlocal;
                }
            }
            return minimglobal;
            //nu functioneaza pentru cazurile in care subsirurile eficiente nu sunt formate din caractere aflate pe pozitii neconsecutive
        }
    }
    public static int existentcharacters(String password)
    {
         int oklowercase=0;
         int okuppercase =0;
         int oknumber = 0;
         for (int i=0;i<password.length();i++)
         {
             if (Character.isDigit(password.charAt(i)))
             {
                 oknumber = 1;
             }
             if(Character.isUpperCase(password.charAt(i)))
             {
                 okuppercase = 1;
             }
             if (Character.isLowerCase(password.charAt(i)))
             {
                 oklowercase = 1;
             }
         }
         return oklowercase+okuppercase+oknumber;
    }
    public static int casespasswordisbelow20length(String password)
    {
        int cat =0;
        for (int i=0;i<password.length()-2;i++)
        {
            int i1=i,contor=1;
            while (i1<password.length()-1 && password.charAt(i1)==password.charAt(i1+1) )
            {
                contor += 1;
                i1 += 1;
            }
            if (contor >=3)
            {
                cat += contor/3;
            }
            i=i1;
        }
        return cat;
    }
}