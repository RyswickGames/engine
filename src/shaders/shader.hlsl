struct PSInput {
    float4 position : SV_POSITION;
    float3 color    : COLOR;
};

PSInput VSMain(uint index : SV_VertexID)
{
    float2 positions[3] = {
        float2(-0.43f, -0.25f),
        float2( 0.0f,   0.5f),
        float2( 0.43f, -0.25f)
    };

    float3 colors[3] = {
        float3(1,0,0),
        float3(0,1,0),
        float3(0,0,1)
    };

    PSInput o;
    o.position = float4(positions[index], 0.0f, 1.0f);
    o.color    = colors[index];
    return o;
}

float4 PSMain(PSInput input) : SV_TARGET
{
    return float4(input.color, 1.0f);
}
