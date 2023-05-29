#include <curl/curl.h>
#include <string>
#include <cstring>
#include <iostream>
#include <sstream>

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int performcURLCall(std::string url, std::string payload, std::string & readBuffer){
	CURLcode ret;
	CURL *hnd;
	struct curl_slist *slist1;
	std::string stToken = "eyJ0eXAiOiJKV1QiLCJhbGciOiJSUzI1NiJ9.eyJhdWQiOiI0MyIsImp0aSI6IjhjZTFlNzUyYzcxZTU3MDkwZTM4NDEzZDkyZTJkOTlkNjQ1NGI5ZmE2YzM0YWUzZDM5ZTRlMjk5MGMzNmU0NTZmMmFmMmYxN2EzY2EwZGVjIiwiaWF0IjoxNjgxNzAxOTQ4LCJuYmYiOjE2ODE3MDE5NDgsImV4cCI6MTcxMzMyNDM0OCwic3ViIjoiMjYiLCJzY29wZXMiOltdfQ.yHhmEY10T1xET-yCtnHm2JxkxpoRDgMZ8vKwa2JqiwuxUdCL1dIQKUaEV7wSt6nq6GemCelq1tT0m-k0xmrGg7Hm4mK3--yfyYI_2quu5V2a5rkWKuO8JD4M8kCWh7Q6tSgRuzYFQtRnVDxSmaxTeL-MpRtGqFtCCSX7WfVWoEwhUw7isoYdN5LCAExR6pSyylioT5dCX6IWBRoHUS1Pfp3K999TllhWqoSH_KE5Qirmc7-i1uXPDMC646V-gSzv_24YvrYVtzSsLeGV3-uFouvSx0a9q1z1TmvOj7ISbpglrAtbZ7KeMtzJ8-9QEJz9oZEUPHU7mm7LWaqL3NVsVHPqWMNDZe66oqbDEcNnkefdMoMcXl4aq1yu6DSe1AGG65OjcFDtgk-xAYpAiE289Pw4uNkxuFFiA7hrfU-MElsizuare5vZH8Go24GZimq68JIjCB8qO12wYf5cJDuc-bFekr0Fiu2U5_LM7k_T-e0ZwdB0bNNkGkN6eZM1uWNR7hNEJoMh4u__7_VrUEhFf_kxq8-v8toAm6hWXozem1nYbx1PToKzY4ZgnR78oKGU0fjmi2mP4UQvN6t_XDmE10imRUJI13pOR_uOvPcICSlUabv19i8MG-GzXKpToE0XuI8zwO7CIEpC16NKbjAGe6EJXjvPuqqSfSfVt9KK9ZI";
	std::string readBufferLocal;
	slist1 = NULL;
	slist1 = curl_slist_append(slist1, "Content-Type: application/json");
    slist1 = curl_slist_append(slist1, "Accept: */*");
	hnd = curl_easy_init();
	curl_easy_setopt(hnd, CURLOPT_BUFFERSIZE, 102400L);
	curl_easy_setopt(hnd, CURLOPT_URL, url.c_str());
    curl_easy_setopt(hnd, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(hnd, CURLOPT_WRITEDATA, &readBufferLocal);
	curl_easy_setopt(hnd, CURLOPT_NOPROGRESS, 0L);
	curl_easy_setopt(hnd, CURLOPT_VERBOSE, 1L);
	curl_easy_setopt(hnd, CURLOPT_POSTFIELDS, payload.c_str());
	curl_easy_setopt(hnd, CURLOPT_POSTFIELDSIZE, std::strlen(payload.c_str()));
	curl_easy_setopt(hnd, CURLOPT_HTTPHEADER, slist1);
	curl_easy_setopt(hnd, CURLOPT_USERAGENT, "curl");
	curl_easy_setopt(hnd, CURLOPT_MAXREDIRS, 50L);
	curl_easy_setopt(hnd, CURLOPT_HTTP_VERSION, (long)CURL_HTTP_VERSION_2TLS);
	curl_easy_setopt(hnd, CURLOPT_TCP_KEEPALIVE, 1L);
	curl_easy_setopt(hnd, CURLOPT_FOLLOWLOCATION, 1L);
	curl_easy_setopt(hnd, CURLOPT_HTTPAUTH, (long)CURLAUTH_BEARER);
	curl_easy_setopt(hnd, CURLOPT_XOAUTH2_BEARER, stToken.c_str());

	ret = curl_easy_perform(hnd);
	
	curl_easy_cleanup(hnd);
	hnd = NULL;
	curl_slist_free_all(slist1);
	slist1 = NULL;
	readBuffer = readBufferLocal;
    std::cout << "DeviceActivation Payload Local:" << readBufferLocal.c_str() << std::endl;
	std::cout << "DeviceActivation Payload : " << readBuffer.c_str() << std::endl;
	std::cout << "Result of CURL Call " << (int)ret << std::endl;
    return (int)ret;
}
/*
 {
    "clerk_id": "0186",
    "provisionId": "",
    "terminal_id": "451-615-951",
    "tickets": [
        {
            "quantity": 1,
            "ticket_type": "123456"
        }
    ]
}
*/
int main (void) {
    std::string res;
    std::stringstream tmp_stream;
	std::string payload;
	std::string tempKey = "976435";
    
	tmp_stream << "{";
	tmp_stream <<   "\"clerk_id\":" << atoi("0186") << ",";
	tmp_stream <<   "\"clerk\":\"0186\",";
	tmp_stream <<    "\"provisionId\":\"placeholder\"," ;
	tmp_stream <<   "\"terminal_id\":\"451-615-951\",";
	tmp_stream <<   "\"tickets\":[";
	tmp_stream <<   "{";
	tmp_stream <<   "\"quantity\":1,";
	tmp_stream <<   "\"ticket_type\":\"123456\"";
	tmp_stream <<   "}]";
	tmp_stream << "}";
    payload = tmp_stream.str();
    std::cout << payload << std::endl;
    performcURLCall("https://app.gobenefits.com.mx/GoBenefitsApiTerminales/api/v3/solicitarBoletos",payload, res);
    return 0;
}