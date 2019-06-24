#include "vcl.h"
#pragma hdrstop  
#include "UREM_DMDocPerCF.h"   
#include "UREM_DMDocPerImpl.h"  
#include "IREM_DMDocPer.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TREM_DMDocPerCF::TREM_DMDocPerCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TREM_DMDocPerCF::~TREM_DMDocPerCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TREM_DMDocPerCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TREM_DMDocPerCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TREM_DMDocPerCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TREM_DMDocPerCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TREM_DMDocPerImpl * ob=new TREM_DMDocPerImpl();  
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
