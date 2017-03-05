for (let i = 0; i < 100; i+=1) {
    let data = Buffer.alloc(1920*1080*3, (i * 10) & 0xFF);
    process.stdout.write( data );
}
