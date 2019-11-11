#!/bin/bash

read -p "What's the IP address you want this program to run into? " server_ip

SECONDS=0
echo "Executing the client 10.000 times..."
for i in {1..10000}; do
    ./prueba_client.out $server_ip SUMA 2 53 >> prueba_client.log
done

calls_duration=$SECONDS
echo "10.000 executions finished $calls_duration seconds."