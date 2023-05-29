import json
import boto3
import uuid

eventClient = boto3.client('events')

def handler(event, context):
    orderId = uuid.uuid4()
    detailJsonString = f'{{"OrderId": "{orderId}"}}'
    print(detailJsonString)
    response = eventClient.put_events(Entries=[{ 
        'Source': 'order.publisher',
        'DetailType':'order-data',
        'Detail': detailJsonString,
        'EventBusName':'OrdersEventBus'
            }]
    )
    print(response)
    return response
