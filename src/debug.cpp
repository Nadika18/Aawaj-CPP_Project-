cout.width(100);
        cout.setf(ios::right);
        changeColor(1);
        cout<<m.messageBody<<endl;
        changeColor(7);
        cout.width(100);
        cout.setf(ios::right);
        cout<<asctime(localtime(&p.msgtime))<<endl;