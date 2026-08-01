#!/bin/bash

sed -i 's/[0-9]\{4\}-[0-9]\{4\}-[0-9]\{4\}-[0-9]\{4\}/XXXX-XXXX-XXXX-XXXX/g' server_access.log

sed -i 's/[0-9]\{16\}/XXXX-XXXX-XXXX-XXXX/g' server_access.log

sed -i 's/HTTP\/1.0/HTTP\/1.1/g' server_access.log

sed -i '/^#/d' server_access.log

