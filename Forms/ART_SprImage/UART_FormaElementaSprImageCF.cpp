#include "vcl.h"
#pragma hdrstop  
#include "UART_FormaElementaSprImageCF.h"   
#include "UART_FormaElementaSprImageImpl.h"  
#include "IART_FormaElementaSprImage.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TART_FormaElementaSprImageCF::TART_FormaElementaSprImageCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TART_FormaElementaSprImageCF::~TART_FormaElementaSprImageCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TART_FormaElementaSprImageCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TART_FormaElementaSprImageCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TART_FormaElementaSprImageCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TART_FormaElementaSprImageCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TART_FormaElementaSprImageImpl * ob=new TART_FormaElementaSprImageImpl();  
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
