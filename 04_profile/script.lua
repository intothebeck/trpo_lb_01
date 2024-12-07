box.cfg{}

local space = box.schema.space.create('space', {if_not_exists = true})
space:create_index('pk', {parts = {{field = 1, type = 'number'}}, if_not_exists = true})

for i = 1, 10000 do
    for i = 1, 1000 do
        local id = math.random(-1000, 1000)
        space:replace({id, string.rep('a', math.abs(id))})
    end

    local _ = space:select()

    box.begin()

    for _, tuple in space:pairs() do
        space:delete(tuple[1])
    end

    box.commit()
end
