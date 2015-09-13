function main
    init('com5', s(o(s(s(o(s(s(o(fin())))))))));

    function init(port, fn)
        try
            disp('0');
            a = arduino(port, 'uno');
            led_fn = @(on) led(a, on);
            fn(led_fn);
        catch ME
            clear a
            rethrow(ME)
        end
    end

    function led(a, on)
        writeDigitalPin(a, 11, on);
        pause(0.25);
    end

    function fn=fin()
        function v=fin_(led_fn) 
            disp('$');
            led_fn(1);
            v = 0;
        end
        fn=@(led_fn) fin_(led_fn);
    end

    function dot(led_fn)
        disp('.')
        led_fn(0)
        led_fn(1)
    end

    function dash(led_fn)
        disp('-')
        led_fn(0)
        led_fn(0)
        led_fn(0)
        led_fn(1)
    end

    function fn=s(next) 
        function s(led_fn)
            disp('s')
            dot(led_fn);
            dot(led_fn);
            dot(led_fn);
            next(led_fn);
        end
        fn=@(led_fn) s(led_fn)
    end

    function fn=o(next)
        function o(led_fn)
            disp('o')
            dash(led_fn);
            dash(led_fn);
            dash(led_fn);
            next(led_fn);
        end
        fn=@(led_fn) o(led_fn)
    end
end


