from bs4 import BeautifulSoup
import requests

url="https://www.mpich.org/static/docs/v3.1/"

#Make a GET Request to fetch the raw HTML content
html_content=requests.get(url).text

#Parse HTML content to Beautiful Soup
content=BeautifulSoup(html_content, 'html.parser')

#get all links
links=content.find_all(href=True)

#scrape the new link
for i in links:
    url2=url+i['href']
    #get the content of the new link
    content2=requests.get(url2).text
    #parse the content to beautfiul soup
    soup=BeautifulSoup(content2,'html.parser')
    #get synopsis
    #synopsis=soup.find_all('pre')
    #print(str(synopsis))
    synopsis=soup.body.pre
    alist=synopsis.contents
    if "\\-c" not in str(alist):
        #reforme the content in a nice way (string)
        print("".join(alist))
