function main
    try
        a = arduino('com3', 'uno');
        for i = 1:10
            s(o(s(a)));
        end
    catch
        clear a
    end
end

function f=led(a, on)
    writeDigitalPin(a, 13, on);
    pause(0.1);
    f = a;
end
    
function f=dot(a)
    led(a, 1);
    led(a, 0);
    led(a, 0);
    led(a, 0);
    led(a, 0);
    f=a;
end

function f=dash(a)
    led(a, 1);
    led(a, 1);
    led(a, 1);
    led(a, 1);
    led(a, 0);
    f=a;
end

function f=s(a)
    f=dot(dot(dot(a)));
end

function f=o(a)
    f=dash(dash(dash(a)));
end

