### DIS Assignment 2
Chat application written in C language, on 1 server and at least 2 client

Done by:
Kirtee: IEC2020102
S.Deepika: IIT2020164

**Step 1.** Start with Server.C and client.C file and generate there outputs with the command in 2 different terminal for clearity.

### Get Output files  

```bash
  gcc Client.c -o Client
  gcc Server.c -o Server
```

**Step 2** Use any port no between 8080 to 9898 to start your server

```bash
./Server 9898
```

**Step 3.** Check your Loopback Running port

```bash
ifconfig
```

**step 4** Connect Client with server

```bash
./Client 127.0.0.1 9898
```

Your Chat application in ready

## Screenshots

![Terminal image](https://github.com/kirteeprajapati/DIS_Chat_app/blob/main/Screenshort/Chat%20application%20terminal.png)

![VS Code and Terminal image](https://github.com/kirteeprajapati/DIS_Chat_app/blob/main/Screenshort/Chat%20application.png)

