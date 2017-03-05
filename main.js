let imgSizeX = 1920;
let imgSizeY = 1080;
let imgNum   = 1000;

let t1 = Date.now();

let data = Buffer.alloc(imgSizeX*imgSizeY*3);

for (var i = 0; i < imgNum; i+=1) {
    var offset = 0;
    for (var y = 0; y < imgSizeY; ++y) {
        for (var x = 0; x < imgSizeX; ++x) {
            offset += 3;
            data[offset+0] = (x+i*5) & 0xFF;
            data[offset+1] = (y+i*(-2)) & 0xFF;
            data[offset+2] = 0x00;
        }
    }
    process.stdout.write( data );
}

let t2 = Date.now();
process.stderr.write(`duration: ${t2-t1}`);