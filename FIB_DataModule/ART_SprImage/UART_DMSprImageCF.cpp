#include "vcl.h"
#pragma hdrstop  
#include "UART_DMSprImageCF.h"   
#include "UART_DMSprImageImpl.h"  
#include "IART_DMSprImage.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TART_DMSprImageCF::TART_DMSprImageCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TART_DMSprImageCF::~TART_DMSprImageCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TART_DMSprImageCF::kanQueryInterface(REFIID id_interface, void**ppv)  
{    
int result=0;  
if (id_interface==IID_IkanUnknown) 
	{  
	*ppv=static_cast<IkanUnknown*> (this);  
	result=-1;  
	} 
else if (id_interface==IID_IkanClassFactory) 
	{  
	*ppv=static_cast<IkanClassFactory*> (this); 
	result=-1; 
	} 
else  
	{   
	*ppv=NULL;  
	result=0;  
	return result;  
	} 
kanAddRef();  
return result;  
}   
//---------------------------------------------------------------
int TART_DMSprImageCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TART_DMSprImageCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TART_DMSprImageCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TART_DMSprImageImpl * ob=new TART_DMSprImageImpl();  
		if (ob->kanQueryInterface(id_interface, ppv)==-1)   
			{       
			result=-1;  
			}    
		else     
			{           
			delete ob;   
			result=0;   
			}      
return result;  
}       
//---------------------------------------------------------------
