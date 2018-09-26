#!/bin/sh

echo "Copying html to local s3 dir"
cp elem-prog.html ../tobilehman.com
echo "Pushing local dir to AWS S3"
(cd ../tobilehman.com && aws s3 sync . s3://tobilehman.com)
