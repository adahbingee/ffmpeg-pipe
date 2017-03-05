const fs = require('fs');

let imgSizeX = 100;
let imgSizeY = 100;
let imgNum   = 1;

function writeOneColor() {
    let color = Buffer.from( [0x0, 
                              0xFF, 
                              0x00] );
    process.nextTick(function () {
        process.stdout.write(color);
    });
}

for (let i = 0; i < imgNum; ++i) {
    for (let y = 0; y < imgSizeY; ++y) {
        for (let x = 0; x < imgSizeX; ++x) {
            writeOneColor();
        }
    }
}