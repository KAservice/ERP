#include "vcl.h"
#pragma hdrstop  
#include "UART_DMSprNaborInfBlockGrpCF.h"   
#include "UART_DMSprNaborInfBlockGrpImpl.h"  
#include "IART_DMSprNaborInfBlockGrp.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TART_DMSprNaborInfBlockGrpCF::TART_DMSprNaborInfBlockGrpCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TART_DMSprNaborInfBlockGrpCF::~TART_DMSprNaborInfBlockGrpCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TART_DMSprNaborInfBlockGrpCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TART_DMSprNaborInfBlockGrpCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TART_DMSprNaborInfBlockGrpCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TART_DMSprNaborInfBlockGrpCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TART_DMSprNaborInfBlockGrpImpl * ob=new TART_DMSprNaborInfBlockGrpImpl();  
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
