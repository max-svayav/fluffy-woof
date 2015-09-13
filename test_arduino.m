function main()
    disp('73')

    a = arduino('COM5')
    onCleanup(@() cleanup);
    a.pinMode(11,'output');

    for i=1:10
        a.digitalWrite(11, bitand(i,1))
        pause(1)
    end
end

function cleanup()
    disp('Cleanup')
    clear a
end