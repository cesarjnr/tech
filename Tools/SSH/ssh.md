### 1. Connecting to a Server

The basic command to connect to a remote server is:

```
ssh <host>
```

You can also specify the username that will be used in this connection in the following way:

```
ssh <username>@<host>
```

You can specify the port by using the `-p` parameter:

```
ssh <username>@<host> -p <port>
```

If you want to specify the private key file to be used in the connection you can use the `-i` parameter:

```
ssh <username>@<host> -i ~/.ssh/id_rsa
```