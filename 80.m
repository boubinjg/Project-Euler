count = 0;
for i = 1:100
    if(sqrt(i) ~= typecast(uint8(sqrt(i)),'int8')) 
        a = vpa(sqrt(i),110);
        s = char(a);
        for j = 1:101
            if(j~=2)
                count = count + str2double(s(j));
            end
        end
    end
end

disp(count);