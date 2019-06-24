#include "vcl.h"
#pragma hdrstop  
#include "UART_DMSprNaborInfBlockSostavGrpCF.h"   
#include "UART_DMSprNaborInfBlockSostavGrpImpl.h"  
#include "IART_DMSprNaborInfBlockSostavGrp.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TART_DMSprNaborInfBlockSostavGrpCF::TART_DMSprNaborInfBlockSostavGrpCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TART_DMSprNaborInfBlockSostavGrpCF::~TART_DMSprNaborInfBlockSostavGrpCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TART_DMSprNaborInfBlockSostavGrpCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TART_DMSprNaborInfBlockSostavGrpCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TART_DMSprNaborInfBlockSostavGrpCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TART_DMSprNaborInfBlockSostavGrpCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TART_DMSprNaborInfBlockSostavGrpImpl * ob=new TART_DMSprNaborInfBlockSostavGrpImpl();  
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
